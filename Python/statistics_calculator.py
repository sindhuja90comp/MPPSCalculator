import math

class StatisticsCalculator:
    
    # A class for calculating basic statistics (mean, median, mode) of a list of numbers.
    
    def __init__(self, data=None):
        """
        Initializes the StatisticsCalculator with a list of data.

        Args:
            data: A list of numbers (integers or floats).  Defaults to an empty list.
        """
        self.data = list(data) if data else []  # Ensure it's a list, handle None

    def calculate_mean(self):
        """
        Calculates the mean (average) of the data.

        Returns:
            The mean of the data, or float('nan') if the data list is empty.
        """
        if not self.data:
            return float('nan')
        return sum(self.data) / len(self.data)

    def calculate_median(self):
        """
        Calculates the median of the data.

        Returns:
            The median of the data, or float('nan') if the data list is empty.
        """
        if not self.data:
            return float('nan')
        sorted_data = sorted(self.data)
        n = len(sorted_data)
        if n % 2 == 0:
            # Even number of elements, average the two middle ones
            mid1 = sorted_data[n // 2 - 1]
            mid2 = sorted_data[n // 2]
            return (mid1 + mid2) / 2
        else:
            # Odd number of elements, take the middle one
            return sorted_data[n // 2]

    def calculate_mode(self):
        """
        Calculates the mode(s) of the data.

        Returns:
            A list of the mode(s) of the data. Returns an empty list
            if the data list is empty, or if there is no unique mode.
        """
        if not self.data:
            return []

        counts = {}
        for number in self.data:
            counts[number] = counts.get(number, 0) + 1

        max_count = 0
        modes = []
        for number, count in counts.items():
            if count > max_count:
                modes = [number]
                max_count = count
            elif count == max_count:
                modes.append(number)
        return modes

def get_integer_list_input():
    """
    Gets a list of integers from the user. Handles input validation and empty input.

    Returns:
        A list of integers entered by the user.  Returns an empty list
        if no valid integers are entered.
    """
    while True:
        input_str = input("Enter a list of integers (with spaces) or type 'done': ")
        if input_str.lower() == 'done':
            return []  # Return an empty list to signal no input

        try:
            numbers = [int(x) for x in input_str.split()]
            if not numbers:
                print("No integers were entered. Please provide a list of integers or 'done'.")
                continue #restart the loop
            return numbers
        except ValueError:
            print("Invalid input. Please enter integers separated by spaces, or 'done'.")
            # No return here, loop back to the beginning of the while loop