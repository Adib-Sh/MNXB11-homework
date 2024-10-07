#include <iostream>
#include <string>

int keyGenerator(const std::string &strFirstArg) {
  int var6 = 0;  // Initialize var6
  // Looping over the size of the passed str argument
  for (size_t i = 0; i < strFirstArg.size(); ++i) {
    var6 += strFirstArg[i];  
  } 
  return var6;  // Return the computed value
}

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

    int key =  keyGenerator(strFirstArg);

    if ((key ^ firstArg * 3) << (fileNameSize & 0x1f) == secondArg) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  }
}