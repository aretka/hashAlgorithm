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
