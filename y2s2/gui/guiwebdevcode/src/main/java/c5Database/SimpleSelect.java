package c5Database;

import java.sql.*;

// NOTE: For this exercise, it is important that derby files are all properly added to the classpath
// In IntelliJ IDEA 2019, you want to go to Project Structure > Modules > Dependencies, and add the lib folder
// the lib folder should contain all the related derby files under "Compile"
// If either: 1. The host string is incorrect or 2. The file cannot be found. SQLException will be displayed.

// NOTE: If successful, the output should still be an error, but in a form of:
//       java.sql.SQLSyntaxErrorException: Table/View 'PROGRAMME' does not exist.
public class SimpleSelect {
    public static void main(String[] args) throws SQLException, ClassNotFoundException {
//        String host = "jdbc:derby://localhost:1527/collegedb;create=true";  --> File, requires service
        String host = "jdbc:derby:memory/collegedb;create=true"; // --> Memory only
        try {
            Connection conn = DriverManager.getConnection(host);
            String sqlInsert =
                    "CREATE TABLE Programme (" +
                    "id int, " +
                    "name varchar(50))";
            String sqlQuery = "SELECT * FROM Programme";
            Statement stmt = conn.createStatement();
            stmt.executeUpdate(sqlInsert);
            ResultSet rs = stmt.executeQuery(sqlQuery);
            while (rs.next()) {
                System.out.println(rs.getString(1) + "\t" + rs.getString(2));
            }
            conn.close();
        } catch (SQLException ex) {
            ex.printStackTrace();
        }
    }
}
