#include <iostream>

#include "Config/ConfigToml.hpp"

int main(int argc, char **argv)
{
    try
    {
        Hermes::ConfigToml config = Hermes::ConfigToml("neoncube.toml");
    }
    catch (std::string Message)
    {
        std::cout << Message << std::endl;
    }
}