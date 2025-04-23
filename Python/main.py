from statistics_calculator import StatisticsCalculator, get_integer_list_input

def main():
    
    # Main function to run the statistics calculation with user input and the StatisticsCalculator class.
    
    print("Welcome to the Statistics Calculator!")
    numbers = get_integer_list_input()

    if not numbers:
        print("No numbers entered. Exiting.")
        return

    calculator = StatisticsCalculator(numbers)  # Create an instance of the class
    mean = calculator.calculate_mean()
    median = calculator.calculate_median()
    modes = calculator.calculate_mode()

    print(f"Numbers: {calculator.data}")  # Access the data from the object
    print(f"Mean: {mean}")
    print(f"Median: {median}")
    print(f"Mode(s): {modes}")

if __name__ == "__main__":
    main()