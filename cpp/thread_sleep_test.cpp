#include <iostream>
#include <chrono>
#include <string>
#include <thread>
 
int main(int argc, char * argv[]) {
  int ms = 0;
  if (argc == 1)
    ms = 1000;
  else
    ms = std::stoi(std::string(argv[1]));
  std::cout << "Hello waiter" << std::endl;
  std::chrono::milliseconds dura(ms);
  std::this_thread::sleep_for(dura);
  std::cout << "Waited " << ms << " ms\n";
  return 0;
}