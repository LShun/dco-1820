package Tutorial5;

import org.junit.Test;

import static org.junit.Assert.*;

public class ValidateIDTest {

    @Test
    public void validateID() {
        assertEquals(false, ValidateID.validateID("b0012")); // below 6 chars
        assertEquals(false, ValidateID.validateID("b00001239")); // above 10 chars
        assertEquals(false, ValidateID.validateID("b00001")); // start with lowercase
        assertEquals(false, ValidateID.validateID("b!0001")); // not letter and digits only
        assertEquals(false, ValidateID.validateID("B00001")); // no lowercase
        assertEquals(false, ValidateID.validateID("ABCDEF")); // no digits
        assertEquals(true, ValidateID.validateID("Bc0001")); // satisfy all criteria
    }
}