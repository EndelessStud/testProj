#include "database.h"

Database::Database() {
  connection = PQconnectdb(
      "dbname=mydb user=myuser password=33333333 host=localhost port=5432");
  if (PQstatus(connection) != CONNECTION_OK) {
    std::cerr << "Connection to database failed: " << PQerrorMessage(connection)
              << std::endl;
    PQfinish(connection);
    connected = false;
  }
}

void Database::insertCountry(const std::string &country) {
  const std::string insertQuery = "INSERT INTO country (name) VALUES ($1)";
  const char *paramValues[1] = {country.c_str()};
  PGresult *res = PQexecParams(connection, insertQuery.c_str(), 1, NULL,
                               paramValues, NULL, NULL, 0);
  if (PQresultStatus(res) != PGRES_COMMAND_OK) {
    std::cerr << "Error insert query " << PQerrorMessage(connection)
              << std::endl;
  } else {
    std::cerr << "Add " << country << " in database" << std::endl;
  }
  PQclear(res);
}
