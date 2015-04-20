library(tools)
allData <- read.csv("output.tsv", sep="\t", header=TRUE)
get_ext <- Vectorize(function(filename) {
    ext <- substr(file_ext(filename), start=1, stop=3)
    if (ext == "py3") {
        ext <- "py"
    }
    else if (ext == "dpr") {
        ext <- "pas"
    }
    return(ext)
})
allData$i_ext <- get_ext(allData$i_filename)
allData$j_ext <- get_ext(allData$j_filename)
summary(as.factor(allData$i_ext))
data    <- data.frame(
    ans     = as.factor(allData$ans),
    dist    = allData$dist_ratio,
    size    = allData$mess_size,
    extpair = as.factor(ifelse(allData$i_ext == allData$j_ext, allData$i_ext, "ne")))
rm(allData)
with(data, plot(dist ~ size, col = ans))

data.split <- split(data, data$size <= 400)
data.small <- data.split$`TRUE`
data.rest  <- data.split$`FALSE`
rm(data.split)

classifier <- glm(ans ~ size + dist, data=data.small, family=binomial)
slope      <- coef(classifier)[2]/(-coef(classifier)[3])
intercept  <- coef(classifier)[1]/(-coef(classifier)[3])
abline(intercept, slope)

classifier <- glm(ans ~ size + dist, data=data.rest, family=binomial)
slope      <- coef(classifier)[2]/(-coef(classifier)[3])
intercept  <- coef(classifier)[1]/(-coef(classifier)[3])
abline(intercept, slope)
