import java.sql.*;
public class DatabaseSetup {
     private static final String DATABASE_URL = "jdbc:mysql://localhost:3306/";

    private static final String DATABASE_USER = "root";

    private static final String DATABASE_PASSWORD = "password";

    public static void main(String[] args){
        try(Connection connection = DriverManager.getConnection(DATABASE_URL, DATABASE_USER, DATABASE_PASSWORD)){
            System.out.println("Connected to the database!");
    setupSchema(connection);
                System.out.println("Database schema created successfully!");
        }
catch (SQLException e){
    e.printStackTrace();
}
}
    private static void setupSchema(Connection connection) throws SQLException {
    String schema = """
    CREATE DATABASE IF NOT EXISTS ZombieApocalypse;
    USE ZombieApocalypse;

    CREATE TABLE IF NOT EXISTS Survivors(
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    age INT,
    gender VARCHAR(10),
    health INT,
    refuge_id INT,
    FOREIGN KEY (refuge_id) REFERENCES Refuges(id)
    );
        

                CREATE TABLE IF NOT EXISTS Zombies (
                    id INT AUTO_INCREMENT PRIMARY KEY,
                    name VARCHAR(100) NOT NULL,
                    type VARCHAR(50),
                    health INT,
                    defeated_by INT,
                    FOREIGN KEY (defeated_by) REFERENCES Survivors(id)
                );

                CREATE TABLE IF NOT EXISTS Refuges (
                    id INT AUTO_INCREMENT PRIMARY KEY,
                    name VARCHAR(100) NOT NULL,
                    location VARCHAR(200),
                    supplies_duration INT
                );

                CREATE TABLE IF NOT EXISTS Supplies (
                    id INT AUTO_INCREMENT PRIMARY KEY,
                    refuge_id INT,
                    item_name VARCHAR(100),
                    quantity INT,
                    expiration_date DATE,
                    FOREIGN KEY (refuge_id) REFERENCES Refuges(id)
                );
                """;

        try (Statement statement = connection.createStatement()) {
            statement.executeUpdate(schema);
}
}
}