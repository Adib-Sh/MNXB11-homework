#include <iostream>
#include <string>

int keycalc(const std::string &strFirstArg) {
  int strsum = 0;
  // Looping over the size of the passed str argument
  for (size_t i = 0; i < strFirstArg.size(); ++i) {
    strsum += strFirstArg[i];  
  } 
  return strsum;
}

int main(int argCount, char *clArg[]) {
  bool bArgCount = (argCount ==3);
  if (bArgCount) {
    //Getting the size of the filename
    std::string fileName{clArg[0]};
    size_t fileNameSize{fileName.size()};

    //Getting the first argument and convert to str
    char firstArg{*(clArg[1])};
    std::string strFirstArg{clArg[1]};

    //Getting the second argument and convert it to integer (string to integer)
    int secondArg{std::atoi(clArg[2])};

    //Calculate the first arg strCount and calculate key
    int key =  keycalc(strFirstArg);
    std::cout << "strSum of '" << strFirstArg << "': " << key << std::endl;

    int calculatedKey = (key ^ firstArg * 3) << (fileNameSize & 0x1f);
    std::cout << "Calculated key: " << calculatedKey << std::endl;
    std::cout << "Entered key by the user: " << secondArg << std::endl;

    //Comparing the calculated key with the user key (second argument)
    if ((key ^ firstArg * 3) << (fileNameSize & 0x1f) == secondArg) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  }
  //Raise an error if not enough arguments are passed
  else {
    std::cout << "Invalid input! Please provide exactly two arguments." << std::endl;
  }
  return 0;
}