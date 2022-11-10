package main

import (
	"fmt"
	"net/http"

	"github.com/gin-gonic/gin"
)

func main() {
	r := gin.Default()
	r.Static("/assets", "./plugins/js")
	r.Delims("${", "}")
	r.LoadHTMLGlob("./webs/*")
	r.GET("/index", func(c * gin.Context) {
		c.HTML(http.StatusOK, "index.html", 
		gin.H{})
	})

	if error := r.Run(":12000"); error != nil {
		fmt.Println(error)
	}
}