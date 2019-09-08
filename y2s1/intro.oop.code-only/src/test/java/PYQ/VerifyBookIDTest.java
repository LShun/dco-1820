package PYQ;

import PYQ.y2018.VerifyBookID;
import org.junit.Test;

import static org.junit.Assert.*;

public class VerifyBookIDTest {

    @Test
    public void length() {
        assertFalse(VerifyBookID.verifyBookId("12345679932183"));
    }

    @Test
    public void frontDigitsCheck() {
        assertFalse(VerifyBookID.verifyBookId("abcde_2018"));
        assertFalse(VerifyBookID.verifyBookId("12abc_2018"));
        assertFalse(VerifyBookID.verifyBookId("abc12_2018"));
    }

    @Test
    public void underscoreCheck() {
        assertFalse(VerifyBookID.verifyBookId("12312a2018"));
    }

    @Test
    public void backDigitsCheck() {
        assertFalse(VerifyBookID.verifyBookId("12312_abcd"));
        assertFalse(VerifyBookID.verifyBookId("12312_20av"));
        assertFalse(VerifyBookID.verifyBookId("12312_a201"));
    }

    @Test
    public void fullCheck() {
        assertTrue(VerifyBookID.verifyBookId("12345_2018"));
    }
}