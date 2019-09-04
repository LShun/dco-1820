package Practical5;

import org.junit.Test;

import static org.junit.Assert.*;

public class ValidatePasswordTest {

    @Test
    public void isValid() {
        assertEquals(true, ValidatePassword.isValid("123456a"));
        assertEquals(false, ValidatePassword.isValid("12345a"));  // password too short
        assertEquals(false, ValidatePassword.isValid("123!456"));  // password have other symbols
        assertEquals(false, ValidatePassword.isValid("1234567")); // only have digits
        assertEquals(false, ValidatePassword.isValid("abcDEFG")); // only have letters
    }
}