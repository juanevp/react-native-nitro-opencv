import {type HybridObject} from "react-native-nitro-modules";

import type {LineTypes, MarkerTypes} from "./constants-image-processing";
import type {MatVector} from "./mat-vector.nitro";
import type {CvMat} from "./mat.nitro";
import type {CvPoint} from "./point.nitro";
import type {CvScalar} from "./scalar.nitro";
import type {CvSize} from "./size.nitro";

export interface Drawing extends HybridObject<{ios: "c++"; android: "c++"}> {
    /**
     * Draws a arrow segment pointing from the first point to the second one.
     * @param img Image
     * @param pt1 The point the arrow starts from.
     * @param pt2 The point the arrow points to.
     * @param color Line color
     * @param thickness Line thickness
     * @param line_type Type of the line. See LineTypes
     */
    arrowedLine(img: CvMat, pt1: CvPoint, pt2: CvPoint, color: CvScalar, thickness: number, line_type: LineTypes): void;

    /**
     * Draws a circle.
     * @param img Image where the circle is drawn.
     * @param center Center of the circle.
     * @param radius Radius of the circle.
     * @param color Circle color.
     * @param thickness Thickness of the circle outline, if positive. Negative values, like FILLED, mean that a filled circle is to be drawn
     */
    circle(img: CvMat, center: CvPoint, radius: number, color: CvScalar, thickness: number, line_type: LineTypes): void;

    /**
     * Clips the line against the image rectangle.
     * The function cv::clipLine calculates a part of the line segment that is entirely within the specified rectangle. it returns false if the line segment is completely outside the rectangle. Otherwise, it returns true .
     * @param imgSize Image size
     * @param pt1 First line point.
     * @param pt2 Second line point.
     */
    clipLine(imgSize: CvSize, pt1: CvPoint, pt2: CvPoint): boolean;

    /**
     * Draws contours outlines or filled contours.
     * The function draws contour outlines in the image if 𝚝𝚑𝚒𝚌𝚔𝚗𝚎𝚜𝚜≥0 or fills the area bounded by the contours if 𝚝𝚑𝚒𝚌𝚔𝚗𝚎𝚜𝚜<0.
     * @param image Destination image.
     * @param contours All the input contours. Each contour is stored as a point vector
     * @param contourIdx Parameter indicating a contour to draw. If it is negative, all the contours are drawn.
     * @param color Color of the contours.
     * @param thickness Thickness of lines the contours are drawn with. If it is negative (for example, thickness=FILLED ), the contour interiors are drawn
     * @param lineType Line connectivity. See LineTypes
     */
    drawContours(
        image: CvMat,
        contours: MatVector,
        contourIdx: number,
        color: CvScalar,
        thickness: number,
        lineType: LineTypes
    ): void;

    /**
     * Draws a marker on a predefined position in an image.
     * @param img Image
     * @param position The point where the crosshair is positioned
     * @param color Line color
     * @param markerType The specific type of marker you want to use, see MarkerTypes
     * @param markerSize Line thickness
     * @param thickness Type of the line, See LineTypes
     * @param line_type The length of the marker axis [default = 20 pixels]
     */
    drawMarker(
        img: CvMat,
        position: CvPoint,
        color: CvScalar,
        markerType: MarkerTypes,
        markerSize: number,
        thickness: number,
        line_type: LineTypes
    ): void;

    /**
     * Draws a simple or thick elliptic arc or fills an ellipse sector.
     * @param img Image
     * @param center Center of the ellipse
     * @param axes Half of the size of the ellipse main axes
     * @param angle Ellipse rotation angle in degrees
     * @param startAngle Starting angle of the elliptic arc in degrees
     * @param endAngle Ending angle of the elliptic arc in degrees
     * @param color Ellipse color.
     * @param thickness Thickness of the ellipse arc outline, if positive. Otherwise, this indicates that a filled ellipse sector is to be drawn
     * @param lineType Type of the ellipse boundary. See LineTypes
     */
    ellipse(
        img: CvMat,
        center: CvPoint,
        axes: CvSize,
        angle: number,
        startAngle: number,
        endAngle: number,
        color: CvScalar,
        thickness: number,
        lineType: LineTypes
    ): void;

    /**
     * Fills a convex polygon.
     * @param img Image
     * @param pts Polygon vertices.
     * @param color Polygon color
     * @param lineType Type of the polygon boundaries. See LineTypes
     */
    fillConvexPoly(img: CvMat, pts: MatVector, color: CvScalar, lineType: LineTypes): void;

    /**
     * Fills the area bounded by one or more polygons
     * @param img Image
     * @param pts Array of polygons where each polygon is represented as an array of points
     * @param color Polygon colo
     * @param lineType Type of the polygon boundaries. See LineTypes
     */
    fillPoly(img: CvMat, pts: MatVector, color: CvScalar, lineType: LineTypes): void;

    /**
     * Draws a line segment connecting two points.
     * @param img Image
     * @param pt1 First point of the line segment
     * @param pt2 Second point of the line segment
     * @param color Line color
     * @param thickness Line thickness
     * @param lineType Type of the line. See LineTypes.
     */
    line(img: CvMat, pt1: CvPoint, pt2: CvPoint, color: CvScalar, thickness: number, lineType: LineTypes): void;

    /**
     * Draws several polygonal curves
     * @param img Image
     * @param pts Array of polygonal curves.
     * @param isClosed Flag indicating whether the drawn polylines are closed or not. If they are closed, the function draws a line from the last vertex of each curve to its first vertex
     * @param color Polyline color
     * @param thickness Thickness of the polyline edges
     * @param lineType Type of the line segments. See LineTypes
     */
    polylines(
        img: CvMat,
        pts: MatVector,
        isClosed: boolean,
        color: CvScalar,
        thickness: number,
        lineType: LineTypes
    ): void;

    /**
     * Draws a simple, thick, or filled up-right rectangle.
     * @param img Image
     * @param pt1 Vertex of the rectangle
     * @param pt2 Vertex of the rectangle opposite to pt1
     * @param color Rectangle color or brightness (grayscale image).
     * @param thickness Thickness of lines that make up the rectangle. Negative values, like FILLED, mean that the function has to draw a filled rectangle
     * @param lineType Type of the line. See LineTypes
     */
    rectangle(img: CvMat, pt1: CvPoint, pt2: CvPoint, color: CvScalar, thickness: number, lineType: LineTypes): void;
}
