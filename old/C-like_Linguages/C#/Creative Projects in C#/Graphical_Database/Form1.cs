using System;
using System.Data;
using System.Data.SQLite;
using System.Windows.Forms;

namespace DatabaseApp {
    public partial class Form 1 : Form
        {
        string connectionString = "Data Source=users.db;Version=3;";
    public Form1() {
        InitializeComponent();
}
    private void CreateDatabase() {
    using (var connection = new SQLiteConnection(connectionString)){
        connection.Open();
        string craeteTableQuery = "CREATE TABLE IF NOT EXISTS Users (Id INTEGER PRIMARY KEY, Name TEXT, Age INTEGER)";
        using (var command = new SQLiteCommand(createTableQuery, connection)) {
command.ExecuteNonQuery();            
}
}        
}
    private void InsertData(string name, int age) {
using (var connection = new SQLiteConnection(connectionString)){
    connection.Open();
    string insertQuery = "INSERT INTO Users (Name, Age) VALUES (@Name, @Age);"
    using (var command = new SQLiteCommand(insertQuery, connection)) {
        command.Parameters.AddWithValue("@Name", name);        command.Parameters.AddWithValue("@Age", age);
command.ExecuteNonQuery();

}
}        
}
private void LoadData() {
    using(var connection = new SQLiteConnection(connectionString)) {
        connection.Open();
        string selectQuery = "SELECT *FROM Users";
        using (var command = new SQLiteCommand(selectQuery, connection))
            {
    SQLiteDataAdapter dataAdapter = new SQLiteDataAdapter(command);
            DataTable dataTable = new DataTable();
            dataAdapter.Fill(dataTable);
            dataGridView.DataSource = dataTable;
}
}
}
private void btnAdd_Click(object sender, EventArgs e)
    {
    string name = txtName.Text;
    int age = (int)numAge.Value;

    if(!string.IsNullOrEmpty(name) && age > 0)
        {
        InsertData(name, age);
        MessageBox.Show("Data added successfully!");
        LoadData();
            
}
else {
    MessageBox.Show("Please enter valid data.");
    
}
}
private void btnLoad_Click(objetc sender, EventArgs e)
    {
    LoadData();
}
private void Form1_Load(object sender, EventArgs e)
    {
    CreateDatabase();
}
}
}
