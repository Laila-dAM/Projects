using Microsoft.OpenApi.Models;

var builder = WebApplication.CreateBuilder(args);

var sampleCourses = new List<Course>
{
    new Course
    {
        Id = 1,
        Title = "Intro to AI",
        Description = "Basics of AI",
        Modules = new List<Module>
        {
            new Module { Id = 1, Name = "Foundations", Content = "..." },
            new Module { Id = 2, Name = "Neural Nets", Content = "..." }
        }
    }
};

var sampleStudents = new List<Student>
{
    new Student
    {
        Id = 1,
        Name = "Laila",
        PerformanceScore = 85,
        CompletedModules = new List<int> { 1 }
    }
};

builder.Services.AddSingleton(new RecommendationService(sampleCourses, sampleStudents));

builder.Services.AddControllers();
builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen(c =>
{
    c.SwaggerDoc("v1", new OpenApiInfo { Title = "CustomPlatform API", Version = "v1" });
});

var app = builder.Build();

app.UseSwagger();
app.UseSwaggerUI();

app.UseHttpsRedirection();
app.UseAuthorization();

app.MapControllers();

app.Run();