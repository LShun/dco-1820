package Practical4;

import org.junit.Test;

import static org.junit.Assert.*;

public class StudentTest {

    Student s1 = new Student("123ABC", "Hello Sky", 12, 100);

    @Test
    public void getID() {
        assertEquals("123ABC", s1.getID());
    }

    @Test
    public void getName() {
        assertEquals("Hello Sky", s1.getName());
    }

    @Test
    public void getQuizTaken() {
        assertEquals(12, s1.getQuizTaken());
    }

    @Test
    public void getTotalQuizScore() {
        assertEquals(100, s1.getTotalQuizScore());
    }

    @Test
    public void setID() {
        s1.setID("13ABC");
        assertEquals("13ABC", s1.getID());
    }

    @Test
    public void setName() {
        s1.setName("Goodbye Sky");
        assertEquals("Goodbye Sky", s1.getName());
    }

    @Test
    public void setQuizTaken() {
        s1.setQuizTaken(10);
        assertEquals(10, s1.getQuizTaken());
    }

    @Test
    public void setTotalScore() {
        s1.setTotalQuizScore(100);
        assertEquals(100, s1.getTotalQuizScore());
    }

    @Test
    public void addQuiz() {
        s1.addQuiz(100);
        assertEquals(22, s1.getQuizTaken());
    }

    @Test
    public void getAverageScore() {
        assertEquals(8.3333, s1.getAverageScore(), 0.0001);
    }

    @Test
    public void getTotalScore() {
        assertEquals(120, s1.getTotalScore());
    }
}