import cv2

def main():
    image = cv2.imread("../resources/test.png")

    if image is None:
        print("Error: couldn't open image")
        exit()

    text = "Cam 1" 
    point = (10, 30) 
    font = cv2.FONT_HERSHEY_COMPLEX_SMALL 
    font_size = 2.0 
    color = (33, 55, 183) 
    thickness = 2 
    cv2.putText(image, text, point, font, font_size, color, thickness) 

    top_left_point = (50, 100)
    bottom_right_point = (200, 300) 
    cv2.rectangle(image, top_left_point, bottom_right_point, color, thickness) 

    center = (200, 200) 
    radius = 222 
    cv2.circle(image, center, radius, color, thickness) 

    cv2.imshow("Image", image) 
    cv2.waitKey(0) 
    cv2.destroyAllWindows() 


if __name__ == "__main__":
    main()

