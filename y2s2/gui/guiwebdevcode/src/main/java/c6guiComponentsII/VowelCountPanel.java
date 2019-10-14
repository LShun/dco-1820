package c6guiComponentsII;

import javax.swing.*;
import java.awt.*;

public class VowelCountPanel extends JPanel {
    private int[] count = new int[5];
    private char[] vowels = {'A', 'E', 'I', 'O', 'U'};
    private String text;

    public VowelCountPanel(String text) {
        this.text = text.toUpperCase();
        countLetters();
        setLayout(new GridLayout(6, 2, 5, 5));
        JLabel vowel = new JLabel("Vowel");
        vowel.setHorizontalAlignment(JLabel.CENTER);
        JLabel jcount = new JLabel("Count");
        jcount.setHorizontalAlignment(JLabel.CENTER);
        add(vowel);
        add(jcount);
        for (int i = 0; i < count.length; i++) {
            JLabel jv = new JLabel(String.valueOf(vowels[i]));
            JLabel jc = new JLabel(String.valueOf(count[i]));
            jv.setHorizontalAlignment(JLabel.CENTER);
            jc.setHorizontalAlignment(JLabel.CENTER);
            add(jv);
            add(jc);
        }
    }

    private void countLetters() {
        for (int i = 0; i < text.length(); i++) {
            switch (text.charAt(i)) {
                case 'A':
                    count[0]++;
                    break;
                case 'E':
                    count[1]++;
                    break;
                case 'I':
                    count[2]++;
                    break;
                case 'O':
                    count[3]++;
                    break;
                case 'U':
                    count[4]++;
                    break;
            }
        }
    }
}
