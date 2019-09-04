package Practical5;

import org.junit.Test;

import static org.junit.Assert.*;

public class generateGreetingTest {

    @Test
    public void getSurname() {
        assertEquals("Ryan", generateGreeting.getSurname(new String[] {"pETER","[RYAN]","Robbin", "Mr"}));
        assertEquals("Smith", generateGreeting.getSurname(new String[] {"JOHN","[SMITH]", "Mr"}));
        assertEquals("Chee", generateGreeting.getSurname(new String[] {"[Chee]","ky", "li", "Mr"}));
    }
}