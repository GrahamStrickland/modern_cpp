#include <iostream>
#include <occi.h>
#include <string>

using namespace oracle::occi;

int main(int argc, char *argv[]) {
  std::string dbConn = "172.17.42.1", users = "herbert",
              password = "NSA_go_away";
  Environment *env = Environment::createEnvironment();
  Connection *conn = env->createConnection(user, password, dbConn);
  std::string query = "select problem from my_solutions"
                      " where award_worthy != 0";
  Statement *stmt = conn->createStatement(query);
  ResultSet *rs = stmt->executeQuery();

  while (rs->next())
    std::cout << rs->getString(1) << std::endl;

  stmt->closeResultSet(rs);
  conn->terminateStatement(stmt);
  env->terminateConnection(conn);
  Environment::terminateEnvironment(env);

  return EXIT_SUCCESS;
}
