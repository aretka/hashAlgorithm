# Hash Algorithm

## Pseudocode

This program calculates 32 HEX hash from any input it receives

    This hash funtion creates four 8 HEX hashes
    HashFunction (input, hash[], sqrtNumArray[], ifNull) {
    
      initialize sum to zero
      initialize multiplySum to one
      initialize sumOfBoth to zero
      initialize i to zero

    if ifNull is true
      runing below displayed while once by replacing (int)input[i] value to 128
     else
      while i is lower than input.length() {
        add value of (int)input[i] to sum
        set multiplySum by multiplying (int)input[i] by multiplySum 
        add sum and multiplySum to sumOfBoth

        XOR hash[0] by (int)input[i]
        XOR hash[1] by sum
        XOR hash[2] by multiplySum
        XOR hash[3] by sumOfBoth

        set hash[0] value by multiplying itself by sqrtNumArray[(int)input[i] % 4]
        set hash[1] value by multiplying itself by sqrtNumArray[sum % 4 + 4]
        set hash[2] value by multiplying itself by sqrtNumArray[multiplySum % 4 + 8]
        set hash[3] value by multiplying itself by sqrtNumArray[sumOfBoth % 4 + 12]

        intitialize ii to zero
        while ii is lower than 4 {
          XOR hash[0] by sqrtNumArray[ii]
          XOR hash[1] by sqrtNumArray[ii+4]
          XOR hash[2] by sqrtNumArray[ii+8]
          XOR hash[3] by sqrtNumArray[ii+12]
          ii++
        }
      i++
    }    
  }

  decimalToHex (hash) {
    set decimal hash values to hex and prints the value
  }

  main () {
  
      initialize 16 sqrtNumArray 
      initialize ifnull and set value to false
      set sqrtNumArray values by sqrt 16 different prime numbers below 100 and multiplying them by 1000000
      initialize input and set its value to given input by reading it

      if input is empty
        ifNull = true
      run hashFuntcion(input, hash[], sqrtNumArray[], ifNull)
      run decimalToHex(hash)
  }

### Eksperimentai su vieno simbolio failais
|Test file name|Generated hash|
|--------------|-------------|
|testFile1_1.txt|1caa8450270147af17ea2c51672d5142|
|testFile1_2.txt|290b8f63175d493b2c63f9ca4d58ac07|

### Eksperimentai su skirtingais 1000 simbolių failais
|Test file name|Generated hash|
|--------------|-------------|
|testFile2_1.txt|dc141b0bd1906882e8f524481a15373f|
|testFile2_2.txt|b1d9fb2b4f164911f025b2c1dacd3d0d|

### Eksperimentai su 1000 simbolių failais kurie skiriasi vienu simboliu
|Test file name|Generated hash|
|--------------|-------------|
|testFile3_1.txt|6b9c96d097f7e78b6a35319644bf1d10|
|testFile2_2.txt|6b9c96d0c378c38766577d06524b068f|

### Eksperimentas su tuščiu failu
|Test file name|Generated hash|
|--------------|-------------|
|testFile4.txt|ae04b2ca14c2f67747734a1122c28f41|

2. Rezultatai:
    * Įvestis gali būti bet kokio dydžio;
    * Išvestis visada yra fiksuoto dydžio
    * Maišos funkcija yra deterministinė, t. y., tam pačiam įvedimui (input'ui) išvedimas (output'as) visuomet yra tas pats.

### 3. Eksperimentas su konstitucija.txt failu
|Test file name|Generated hash|Time taken|
|--------------|-------------|---------|
|testFile4.txt|ae04b2ca14c2f67747734a1122c28f41|0.001s|

