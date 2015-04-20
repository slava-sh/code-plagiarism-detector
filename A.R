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
    ratio   = allData$dist_ratio,
    dist    = allData$dist,
    size    = allData$mess_size,
    extpair = as.factor(ifelse(allData$i_ext == allData$j_ext, allData$i_ext, "ne")))
rm(allData)
with(data, plot(ratio ~ size, col=ans, pch=20, cex=0.4))

rect(400, 0.35/2, 410, 0.35, col="lightpink", border=NA)

data.split <- split(data, data$size <= 400 - 40)
data.small <- data.split$`TRUE`
data.rest  <- data.split$`FALSE`
rm(data.split)

classifier <- glm(ans ~ size + ratio, data=data.small, family=binomial)
slope      <- coef(classifier)[2]/(-coef(classifier)[3])
intercept  <- coef(classifier)[1]/(-coef(classifier)[3])
abline(intercept, slope)
print(c(intercept, slope))

classifier <- glm(ans ~ size + ratio, data=data.rest, family=binomial)
slope      <- coef(classifier)[2]/(-coef(classifier)[3])
intercept  <- coef(classifier)[1]/(-coef(classifier)[3])
abline(intercept, slope)
print(c(intercept, slope))

abline(0.228, 0)
