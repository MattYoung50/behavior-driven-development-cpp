## Environment
- This was tested and ran on RHEL 7 leveraging the devtoolset-8

## References
- This leverages [GUnit](https://github.com/cpp-testing/GUnit) to extend GTest and add [BDD](https://cucumber.io/docs/bdd/) capabilities to it

## Running Calculator App
```console
$ make run
```

## Running Calculator Unit Tests
```console
$ make runtests
```

## Running Calculator BDD Tests
```console
$ make test
$ SCENARIO="test/BDD/calculator.feature" bin/runtests --gtest_filter="Calc Addition.Add two numbers"
```

## Running All Tests
```console
$ SCENARIO="test/BDD/calculator.feature" bin/runtests
```



