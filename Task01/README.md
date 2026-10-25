ASK 1 – Understand the Problem and Identify the Data
1. Inputs and Outputs
Inputs:
Previous meter reading: The reading recorded in the previous month.
Current meter reading: The reading recorded in the current month.
Household number: Identifies each house.
Category: Identifies the household's electricity tariff category.
Outputs:
Units consumed: Current reading minus previous reading, considering meter rollover.
Energy charge: Amount calculated based on electricity consumption slabs.
Fixed charge: ₹50 per household.
Total bill: Fixed charge + energy charge.
2. Constants
The following values remain unchanged during program execution:
First 100 units are free.
Units 101–200 cost ₹2.25 per unit.
Units above 200 cost ₹4.50 per unit.
Fixed charge is ₹50.
These values should be defined as constants so tariff changes can be made easily.
3. Values and Data Types
Meter readings are non-negative integers.
Units consumed are integers.
Electricity charges can contain paise.
The total bill for many households can become very large.
Household numbers can be stored as integers or strings, depending on their format.
4. Rules and Assumptions
The electricity bill must never be negative.
Total bill = Fixed charge + Energy charge.
Meter rollover must be handled correctly.
Money should be stored in paise to avoid floating-point rounding errors.
Meter readings are assumed to be valid readings from a 16-bit meter register.
5. Alternative Concept: Text vs Integer Readings
If meter readings are stored as text, such as "01530", they must be converted into numbers before calculating consumption.
If a reading contains d digits, conversion takes O(d) time. Comparing two text readings may also take O(d) time.
Integer readings allow direct arithmetic and comparison, which take O(1) time for fixed-size integer types.
Text requires space proportional to the number of digits, O(d), whereas a fixed-size integer uses constant space, O(1).
Conclusion: Integer readings are more suitable for electricity billing because they simplify calculations and use fixed memory
