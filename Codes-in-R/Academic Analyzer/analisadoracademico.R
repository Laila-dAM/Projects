notas <- c(7.5, 8.2, 6.3, 5.9, 9.1, 7.0, 8.4, 6.8, 7.3, 5.5)

average_class <- mean(notas)

above_average <- notas[notas > average_class] 

rating <- ifelse(notas >= 8, "Excellent",
                 ifelse(notas >= 6, "Good",
                        ifelse(notas >= 4, "Regular", "Insufficient"))) 

report <- data.frame(Student = 1:length(notas), Grade = notas, Rating = rating) 

hist(notas, main = "Grade Distribution", xlab = "Grades", col = "lightblue", border = "black") 

list(Class_Average = average_class, Students_Above_Average = above_average, Report = report)
