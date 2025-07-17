public class Course {
    public int Id { get; set; }
    public string Title { get; set; } = string.Empty;             
    public string Description { get; set; } = string.Empty;       
    public List<Module> Modules { get; set; } = new List<Module>(); 
}
