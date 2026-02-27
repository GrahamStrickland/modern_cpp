#include <iostream>
#include <memory>
#include <occi.h>
#include <string>

struct environment_deleter {
  void operator()(Environment *env) { Environment::terminateEnvironment(env); }
};

struct connection_deleter {
  connection_deleter(std::shared_ptr<Environment> env) : env{env} {}
  void operator()(Connection *conn) { env->terminateConnection(conn); }
  std::shared_ptr<Environment> env;
};

struct result_set_deleter {
  result_set_deleter(std::shared_ptr<Connection> conn, Statement *stmt)
      : conn{conn}, stmt{stmt} {}
  void operator()(ResultSet *rs) {
    stmt->closeResultSet(rs);
    conn->terminateStatement(stmt);
  }
  std::shared_ptr<Connection> conn;
  Statement *stmt;
};

class db_manager {
public:
  using ResultSetSharedPtr = std::shared_ptr<ResultSet>;

  db_manager(std::string const &dbConnection, std::string const &dbUser,
             std::string const &dbPw)
      : environment{Environment::createEnvironment(), environment_deleter{}},
        connection{environment->createConnection(dbUser, dbPw, dbConnection),
                   connection_deleter{environment}} {}
  ResultSetSharedPtr query(const std::string &q) const {
    Statement *stmt = connection->createStatement(q);
    ResultSet *rs = stmt->executeQuery();
    auto deleter = result_set_deleter{connection, stmt};

    return ResultSetSharedPtr{rs, deleter};
  }

private:
  std::shared_ptr<Environment> environment;
  std::shared_ptr<Connection> connection;
};

int main(int argc, char *argv[]) {
  db_manager db("172.17.42.1", "herbert", "NSA_go_away");
  auto rs = db.query("select problem from my_solutions "
                     "   where award_worth != 0");
  while (rs->next())
    std::cout << rs->getString(1) << std::endl;
  return EXIT_SUCCESS;
}
