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

## TASK 2 – Choose the Data Types

### 1. Data Types and Their Uses

- `unsigned short`: Used to store meter readings from 0 to 65535.
- `int`: Used to store electricity units consumed.
- `long`: Used to store the electricity bill in paise.
- `long long`: Used to store the total bills of a large number of households.
- `float` and `double`: Used for decimal calculations, but not preferred for storing money because rounding errors can occur.

### 2. Size and Range

The size of a data type can be checked using `sizeof()` in C.

The limits of integer types can be checked using `limits.h`, and floating-point limits can be checked using `float.h`.

### 3. Why Store Money in Paise?

Money should be stored as integer paise instead of floating-point rupees. This avoids rounding errors during billing.

For example:
- ₹50.00 = 5000 paise
- ₹162.50 = 16250 paise

### 4. Meter Rollover

A 16-bit unsigned meter register can store values from 0 to 65535. After 65535, it rolls over to 0.

For example, if the previous reading is 65400 and the current reading is 120, the consumption is 256 units.
### 5. Float Rounding Example for 4,000 Bills

Floating-point numbers cannot represent every decimal value exactly. Therefore, small rounding errors may occur when many bills are added.

For example, suppose 4,000 bills each contain ₹0.10.

Expected total:

4000 × ₹0.10 = ₹400.00

If the bills are stored and added using floating-point arithmetic, the calculated total may differ slightly from ₹400.00 because of representation and rounding errors.

If the same amount is stored as integer paise, each bill is 10 paise.

4000 × 10 = 40000 paise = ₹400.00

Integer paise gives the exact result for this calculation, provided the integer type does not overflow.
### 7. Alternative Concept: Double Rupees vs Integer Paise

An alternative method is to store money as `double` in rupees instead of storing it as `long` in paise.

**Method 1: Double rupees**

The bill is calculated and stored using decimal rupee values. Since floating-point numbers cannot represent every decimal value exactly, small rounding errors may occur. Rounding should be applied when converting the calculated bill into paise or displaying the final amount, according to the billing rules.

**Method 2: Integer paise**

The bill is stored as an integer number of paise. For example, ₹162.50 is stored as 16250 paise. Addition and subtraction remain exact as long as the integer type does not overflow.

**Time Complexity**

Both methods require O(1) time for each addition. Therefore, adding n bills takes O(n) time in either method.

**Space Complexity**

A `double` typically occupies 8 bytes, while a `long` occupies 4 or 8 bytes depending on the system. The actual sizes can be checked using `sizeof()`.

**Rounding Error Comparison**

When many floating-point values are added, small representation errors can accumulate. The total error depends on the values and the order of calculations; it is not necessarily the same for every set of bills.

Integer paise avoids floating-point representation errors during addition, provided the integer total remains within its permitted range.

**Conclusion**

Integer paise is the preferred method for this billing program because it supports exact monetary arithmetic for amounts expressed in whole paise. `double` may be useful for other calculations, but it requires careful handling of rounding when calculating monetary amounts.
### TASK 3 – Define the Constants

**1. Use of #define**

`#define` is a preprocessor directive used to define symbolic constants. It replaces the constant name with its value before compilation.

Example:
```c
#define RATE2_PAISE 225
```

**2. Use of const**

The `const` keyword defines a variable whose value cannot be changed through that variable after initialization.

Example:
```c
const int rate = 225;
```

**3. Use of enum**

`enum` is used to define named integer constants, especially for a set of related values.

Example:
```c
enum Category { DOMESTIC = 1, COMMERCIAL = 2 };
```

**4. Difference between #define and const**

- `#define` is processed before compilation and does not create a variable by itself.
- `const` has a data type and follows normal scope rules.
- A `const` variable can be easier to inspect in a debugger.
- Neither choice automatically makes a value use less memory in every situation.

**5. Naming conventions**

Constant names are usually written in uppercase letters with underscores, such as `SLAB1_UNITS`, `RATE2_PAISE`, and `FIXED_CHARGE_PAISE`. This makes the program easier to read and maintain.

**Conclusion:** Using named constants keeps tariff values in one place. If the tariff changes, the programmer can update the definition instead of searching throughout the program.


