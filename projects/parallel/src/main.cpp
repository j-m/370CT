#include <iostream>
#include <thread>

[DllImport("kernel32.dll")]
[return: MarshalAs(UnmanagedType.Bool)]
static extern bool GetPhysicallyInstalledSystemMemory(out long TotalMemoryInKilobytes);

void part1() {
  const unsigned int numberOfCores = std::thread::hardware_concurrency();
  const unsigned int clockSpeed = 0;
  const long systemRAM = 0;
  GetPhysicallyInstalledSystemMemory(out memKb);
  const unsigned int homeFolderMBs = 0;
  std::cout << "Total core count: " << numberOfCores << std::endl; 
  std::cout << "Core clock speed: " << clockSpeed << std::endl; 
  std::cout << "Total system RAM: " << systemRAM << "GB" << std::endl; 
  std::cout << "Home folder size: " << homeFolderMBs << std::endl; 
}

int main(void) {
  part1();
  return 0;
}
