#include "catch.hpp"
#include "UtilityFunctions.hpp"
#include "stubs/FixedNumberGenerator.hpp"

SCENARIO("check createGenerator() function")
{
    GIVEN("Generator type FIBONACCI")
    {
        auto type = GeneratorType::FIBONACCI;

        WHEN("Generator is created with provided type")
        {
            auto generator = createGenerator(type);

            THEN("It should not be a null pointer")
            {
                CHECK(generator);
            }
        }
    }

    GIVEN("Not existing generator type")
    {
        auto type = static_cast<GeneratorType>(-1);

        WHEN("Generator is created with provided type")
        {
            THEN("It should throw logic_error")
            {
                CHECK_THROWS_AS(createGenerator(type), std::logic_error);
            }
        }
    }
}

SCENARIO("check sumGeneratedNumbers() function")
{
    GIVEN("FixedNumberGenerator stub and numberOfValues = 10")
    {
        auto generator = std::make_unique<FixedNumberGenerator>();
        auto numberOfValues = 10;

        WHEN("sumGeneratedNumbers is called")
        {
            auto result = sumGeneratedNumbers(std::move(generator), numberOfValues);

            THEN("It should return 420")
            {
                CHECK(result == numberOfValues * 42);
            }
        }
    }
}

SCENARIO("check sumNumbersFromGenerators() function")
{
    GIVEN("Empty generators collection and numberOfValues = 1")
    {
        std::vector<GeneratorType> collection = {};
        auto numberOfValues = 1;

        WHEN("sumNumbersFromGenerators is called")
        {
            auto result = sumNumbersFromGenerators(collection, numberOfValues);

            THEN("It should return 0")
            {
                CHECK(result == 0);
            }
        }
    }
}

SCENARIO("check sumNumbersFromGenerators() function only FIBONACCI(0)")
{
    GIVEN("Only FIBONACCI in generators collection and numberOfValues = 0")
    {
        std::vector<GeneratorType> collection = {GeneratorType::FIBONACCI};
        auto numberOfValues = 0;

        WHEN("sumNumbersFromGenerators is called")
        {
            auto result = sumNumbersFromGenerators(collection, numberOfValues);

            THEN("It should return 0")
            {
                CHECK(result == 0);
            }
        }
    }
}

SCENARIO("check sumNumbersFromGenerators() function only FIBONACCI(1)")
{
    GIVEN("Only FIBONACCI in generators collection and numberOfValues = 1")
    {
        std::vector<GeneratorType> collection = {GeneratorType::FIBONACCI};
        auto numberOfValues = 1;

        WHEN("sumNumbersFromGenerators is called")
        {
            auto result = sumNumbersFromGenerators(collection, numberOfValues);

            THEN("It should return 1")
            {
                CHECK(result == 1);
            }
        }
    }
}


SCENARIO("check sumNumbersFromGenerators() function only FIBONACCI(5)")
{
    GIVEN("Only FIBONACCI in generators collection and numberOfValues = 5")
    {
        std::vector<GeneratorType> collection = {GeneratorType::FIBONACCI};
        auto numberOfValues = 5;

        WHEN("sumNumbersFromGenerators is called")
        {
            auto result = sumNumbersFromGenerators(collection, numberOfValues);

            THEN("It should return 12")
            {
                CHECK(result == 12);
            }
        }
    }
}

SCENARIO("check sumNumbersFromGenerators() function only PRIME(0)")
{
    GIVEN("Only PRIME in generators collection and numberOfValues = 0")
    {
        std::vector<GeneratorType> collection = {GeneratorType::PRIME};
        auto numberOfValues = 0;

        WHEN("sumNumbersFromGenerators is called")
        {
            auto result = sumNumbersFromGenerators(collection, numberOfValues);

            THEN("It should return 0")
            {
                CHECK(result == 0);
            }
        }
    }
}

SCENARIO("check sumNumbersFromGenerators() function only PRIME(1)")
{
    GIVEN("Only PRIME in generators collection and numberOfValues = 1")
    {
        std::vector<GeneratorType> collection = {GeneratorType::PRIME};
        auto numberOfValues = 1;

        WHEN("sumNumbersFromGenerators is called")
        {
            auto result = sumNumbersFromGenerators(collection, numberOfValues);

            THEN("It should return 2")
            {
                CHECK(result == 2);
            }
        }
    }
}

SCENARIO("check sumNumbersFromGenerators() function only PRIME(5)")
{
    GIVEN("Only PRIME in generators collection and numberOfValues = 5")
    {
        std::vector<GeneratorType> collection = {GeneratorType::PRIME};
        auto numberOfValues = 5;

        WHEN("sumNumbersFromGenerators is called")
        {
            auto result = sumNumbersFromGenerators(collection, numberOfValues);

            THEN("It should return 28")
            {
                CHECK(result == 28);
            }
        }
    }
}

SCENARIO("check sumNumbersFromGenerators() function FIBONACCI(5) + PRIME(5)")
{
    GIVEN("FIBONACCI and PRIME generators in collection and numberOfValues = 5")
    {
        std::vector<GeneratorType> collection = {GeneratorType::FIBONACCI, GeneratorType::PRIME};
        auto numberOfValues = 5;

        WHEN("sumNumbersFromGenerators is called")
        {
            auto result = sumNumbersFromGenerators(collection, numberOfValues);

            THEN("It should return 40")
            {
                CHECK(result == 40);
            }
        }
    }
}
