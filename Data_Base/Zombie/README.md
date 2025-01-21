# Zombie Apocalypse Project

This project simulates a database and a Java application to manage data in a zombie apocalypse scenario. It includes survivors, hideouts, zombies, and supplies.

## Features
- Track how many zombies each survivor has defeated.
- Analyze the duration and expiration of supplies in hideouts.
- Count survivors per hideout and classify hideouts.

## Project Structure
- **`sql/`**: SQL scripts for database queries and schema setup.
- `schema.sql`: Create the database and tables.
- `zombies_defeated.sql`: Query to count zombies defeated by each survivor.
- `supply_duration.sql`: Query to calculate the duration and expiration of supplies in hideouts.
- `refuge_survivors.sql`: Query to count survivors in each hideout.
- **`src/`**: Source code for the Java application.
- `Main.java`: Executes database queries and displays the results.
- `DatabaseSetup.java`: Configures the database schema programmatically.

## Prerequisites
- **MySQL**: Installed and running.
- **Java**: JDK installed (version 8+ recommended).
- **JDBC Driver**: Ensure that MySQL Connector/J is included in the classpath.