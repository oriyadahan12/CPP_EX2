//oriyati0701@gmail.com | 327510616
 

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h" // Include the Doctest framework header
using namespace doctest;

const int MIN_TESTS = 20; // Minimum number of tests required

int return_code = -1; // Return code to indicate success or failure

/**
 * @brief Custom reporter to count the number of assertions made in the tests.
 */
struct ReporterCounter : public ConsoleReporter {
    ReporterCounter(const ContextOptions &input_options)
        : ConsoleReporter(input_options) {}

    /**
     * @brief Called when the test run ends.
     * 
     * Checks if the number of assertions made meets the minimum threshold.
     * If not, outputs a message indicating the need for more tests and sets the return code accordingly.
     */
    void test_run_end(const TestRunStats &run_stats) override {
        if (run_stats.numAsserts >= MIN_TESTS) {
            return_code = 0; // Success
        } else {
            std::cout << "Please write at least " << MIN_TESTS << " tests! You only have " << run_stats.numAsserts << " tests." << std::endl;
            return_code = 1; // Failure
        }
    }
};

REGISTER_REPORTER("counter", 1, ReporterCounter); // Register the custom reporter

/**
 * @brief Main function to run tests.
 * 
 * Sets up the testing context, adds the custom reporter, and runs the tests.
 * Returns the appropriate return code based on the success or failure of the tests.
 */
int main(int argc, char **argv) {
    Context context;
    context.addFilter("reporters", "counter"); // Add the custom reporter
    context.run(); // Run the tests
    return return_code; // Return the appropriate return code
}
