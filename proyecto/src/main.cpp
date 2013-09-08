#include "dataCV"

int main(){
dataCV::mysql_connect("test", "localhost", "root", "root");
dataCV::mysql_query("SELECT * FROM wave01;", 1, "voltage");
}
