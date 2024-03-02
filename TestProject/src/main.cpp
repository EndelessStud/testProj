#include <iostream>
#include <publisher.h>
#include <string>
#include <subscriber.h>
#include <database.h>

using namespace std;

int main(int argc, char *argv[]) {
  try {
    if (argc > 3 || argc == 1) {
      cerr << "Need 2 arg: pub <host> or sub" << endl;
      return 0;
    }
    if (string(argv[1]) == "sub") {
      Subscriber sub;
      int countTry = 0;
      sub.tryConnect();
      while (true) {
        if (!sub.inConnection) {
          sub.tryConnect();
          countTry++;
          if(countTry == 10){
              return 0;
          }
        }
      }
    } else if (string(argv[1]) == "pub" && argc == 3) {
      Publisher publisher;
      if(publisher.sendToBroker(publisher.getResponse(string(argv[2])))){

      }
    } else {
        cerr << "Usage: pub <host>" << endl;
        return 0;
    }
  } catch (std::exception &e) {
    cerr << e.what() << std::endl;
  }
  return 0;
}
