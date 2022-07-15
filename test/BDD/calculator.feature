Feature: Calculator Addition
  In order to avoid silly mistakes
  As a math idiot 
  I want to be told the sum of two numbers

  Scenario Outline: When Add is pressed, the correct result should be calculated
    Given I have entered first input <input_1> into the calculator
    And I press add
    And I have entered second input <input_2> into the calculator
    When I press equals
    Then the correct result should be <result>

  Examples:
    | input_1 | input_2 | result |
    | 20      | 30      | 50     |
    | 2       | 5       | 7      |
    | 0       | 40      | 40     |

  Scenario: When Add is pressed with a negative number, the correct result should be calculated
    Given I have entered first input -20 into the calculator
    And I press add
    And I have entered second input 20 into the calculator
    When I press equals
    Then the correct result should be 0
