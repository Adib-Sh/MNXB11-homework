#include <iostream>
#include <string>
int main(int argCount, char *clArg[]) {
  bool bArgCount = (argCount ==3);
  if (bArgCount) {
    //These commands get the size of the filename
    std::string fileName{clArg[0]};
    size_t fileNameSize{fileName.size()};

    //These commands get the first argument and convert to str
    char firstArg{*(clArg[1])};
    std::string strFirstArg{clArg[1]};

    //These command get the second argument and convert it to integer (string to integer)
    int secondArg{std::atoi(clArg[2])};

    
    auto var6{0};
    auto var7{0};
    
    while (true) {
      var6 += strFirstArg[var7++];
      if (var7 >= static_cast<int>(strFirstArg.size())) {
        break;
      }
    }
    if ((var6 ^ firstArg * 3) << (fileNameSize & 0x1f) == secondArg) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  }
}