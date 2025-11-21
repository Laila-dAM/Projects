ᴄᴏᴅᴇ 👾

---

# Custom Learning Platform

## What is it?

A basic backend API built in C# using ASP.NET Core that models a personalized course recommendation system. It connects data from students, modules, and courses, and uses a recommendation service to suggest learning paths.

## How to use?

1. Make sure you have the [.NET SDK](https://dotnet.microsoft.com/en-us/download) installed.

2. Open a terminal in the project folder and build the project:

```bash
dotnet build
```

3. Run the API server:

```bash
dotnet run
```

4. Once running, the API will be available at:

```bash
http://localhost:5000/api/course
```

5. You can test the API using tools like Postman or curl.

Features
- Organized structure with Course, Student, and Module entities
- Smart recommendation logic via RecommendationService
- Clean separation of concerns (Controller, Models, Service)
- ASP.NET Web API architecture

Folder Structure
```bash
📁 Custom Platform/
├── CourseController.cs         # Main API controller
├── Course.cs                   # Course entity
├── Student.cs                  # Student entity
├── Module.cs                   # Module entity
├── RecommendationService.cs   # Business logic for recommendations
└── README.md                   # Project info
```

## Demo

📹 [Watch it run](link)

---

<p align="center">૮ ˙Ⱉ˙ ა learn or perish</p>
