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
### 6. Conclusion

Choosing suitable data types prevents overflow and improves billing accuracy. Integer paise is suitable for money calculations, while `long long` can store large totals.
