package Practical5;

import org.junit.Assert;
import org.junit.Test;

import static org.junit.Assert.*;

public class CountLetterTest {

    @Test
    public void countLetter() {
        Assert.assertEquals(0, (CountLetter.countLetter("c", 'a')));
        Assert.assertEquals(1, (CountLetter.countLetter("b", 'b')));
        Assert.assertEquals(2, (CountLetter.countLetter("aab", 'a')));
    }
}