package main

import (
	"fmt"
	"net/http"

	"github.com/gin-gonic/gin"
)

func main() {
	r := gin.Default()
	r.Static("/assets", "./html-app/src/assets")
	r.Delims("${", "}")
	r.LoadHTMLGlob("./html-app/public/*")
	r.GET("/index", func(c * gin.Context) {
		c.HTML(http.StatusOK, "index.html", 
		gin.H{})
	})

	if error := r.Run(":12500"); error != nil {
		fmt.Println(error)
	}
}