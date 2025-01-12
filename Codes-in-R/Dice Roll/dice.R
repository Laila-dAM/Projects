n <- 1000
rolls <- sample(1:6, n, replace = TRUE)
frequency <- table(rolls)
theoretical_probability <- rep(1/6, 6)
real_probability <- frequency / n
print(frequency)
cat("Theoretical Probability: ", theoretical_probability, "\n")
cat("Real Probability: ", real_probability, "\n")
barplot(frequency, main = "Roll Frequency", xlab = "Die Faces", ylab = "Frequency", col = "lightblue")
