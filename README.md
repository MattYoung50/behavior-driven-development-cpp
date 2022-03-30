## Environment
- This was tested and ran on RHEL 7 leveraging the devtoolset-8

## References
- This leverages [GUnit](https://github.com/cpp-testing/GUnit) to extend GTest and add [BDD](https://cucumber.io/docs/bdd/) capabilities to it

## Running Calculator App
```console
% make run
```

## Running Calculator Unit Tests
```console
% make runtests
```

## Running Calculator BDD Tests
```console
% make test
% SCENARIO="test/BDD/calculator.feature" bin/runtests --gtest_filter="Calc Addition.Add two numbers"
```

## Running All Tests
```console
% SCENARIO="test/BDD/calculator.feature" bin/runtests
```

## Making This Repo Work in a Different Environment
- If you want to build this in any other environment, you will have to natively compile the libs for your target environment. See console commands below
```console 
% git clone https://github.com/cpp-testing/GUnit.git
% cd GUnit
% git submodule update --init --recursive
% mkdir build && cd build
% cmake ..
% cmake --build . --target install
```
- The key libs you need are in this repo under lib
    - fmem
    - gherkin
    - gherkin-cpp
    - gtest
    - gunit
    - json (Header only)

