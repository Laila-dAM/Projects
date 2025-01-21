import java.sql.*;

public class Main {
    private static final String DATABASE_URL = "jdbc:mysql://localhost:3306/ZombieApocalypse";
    private static final String DATABASE_USER = "root";
    private static final String DATABASE_PASSWORD = "password";

    public static void main(String[] args) {
        try (Connection connection = DriverManager.getConnection(DATABASE_URL, DATABASE_USER, DATABASE_PASSWORD)) {
            System.out.println("Connected to the database!");

            System.out.println("\nZombies Defeated:");
            runZombiesDefeatedQuery(connection);

            System.out.println("\nSupply Duration:");
            runSupplyDurationQuery(connection);

            System.out.println("\nRefuge Survivors:");
            runRefugeSurvivorsQuery(connection);

        } catch (SQLException e) {
            e.printStackTrace();
}
}

    private static void runZombiesDefeatedQuery(Connection connection) throws SQLException {
        String query = """
                SELECT s.name AS SurvivorName, COUNT(z.id) AS ZombiesDefeated
                FROM Survivors s
                JOIN Zombies z ON s.id = z.defeated_by
                GROUP BY s.id;
                """;

        try (PreparedStatement statement = connection.prepareStatement(query);
             ResultSet resultSet = statement.executeQuery()) {
            while (resultSet.next()) {
                String survivorName = resultSet.getString("SurvivorName");
                int zombiesDefeated = resultSet.getInt("ZombiesDefeated");
                System.out.printf("Survivor: %s, Zombies Defeated: %d%n", survivorName, zombiesDefeated);
}
}
}

    private static void runSupplyDurationQuery(Connection connection) throws SQLException {
        String query = """
                SELECT r.name AS RefugeName, r.supplies_duration, 
                       SUM(DATEDIFF(s.expiration_date, CURDATE())) AS DaysUntilSuppliesExpire
                FROM Refuges r
                JOIN Supplies s ON r.id = s.refuge_id
                GROUP BY r.id;
                """;

        try (PreparedStatement statement = connection.prepareStatement(query);
             ResultSet resultSet = statement.executeQuery()) {
            while (resultSet.next()) {
                String refugeName = resultSet.getString("RefugeName");
                int suppliesDuration = resultSet.getInt("supplies_duration");
                int daysUntilExpire = resultSet.getInt("DaysUntilSuppliesExpire");
                System.out.printf("Refuge: %s, Supplies Duration: %d days, Days Until Supplies Expire: %d%n",
                        refugeName, suppliesDuration, daysUntilExpire);
}
}
}

    private static void runRefugeSurvivorsQuery(Connection connection) throws SQLException {
        String query = """
                SELECT r.name AS RefugeName, COUNT(s.id) AS SurvivorCount
                FROM Refuges r
                JOIN Survivors s ON r.id = s.refuge_id
                GROUP BY r.id
                ORDER BY SurvivorCount DESC;
                """;

        try (PreparedStatement statement = connection.prepareStatement(query);
             ResultSet resultSet = statement.executeQuery()) {
            while (resultSet.next()) {
                String refugeName = resultSet.getString("RefugeName");
                int survivorCount = resultSet.getInt("SurvivorCount");
                System.out.printf("Refuge: %s, Survivor Count: %d%n", refugeName, survivorCount);
}
}
}
}
