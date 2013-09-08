#include <string>
#include <iostream>
#include <mysql++.h>

class dataCV{
protected:
  string database;
  string server;
  string username;
  string password;
public:
  dataCV(string name);
  virtual ~dataCV(void);
  virtual bool mysql_connect(string database, string server, string username, string password){
  mysqlpp::Connection conn(false);
  conn.connect(database, server, username, password);
  mysqlpp::Query query = conn.query();
  return true;
  }
  virtual bool mysql_query(string sql_command, int cell, string field){
  query << sql_command;
  mysqlpp::StoreQueryResult line = query.store();
  cout << line[cell][field]; 
  return true;
  }
};
