#ifdef GL_ES
precision mediump float;
#endif

uniform  vec2 u_resolution;
uniform  float u_time;

float circleshape(vec2 position, float radius){
    return step(radius, length(position - vec2(0.5)));
}

void main(){
 vec2 position = gl_FragCoord.xy / u_resolution;

 vec3 color = vec3(1.0, 0.3, 0.0);

 vec2 translate = vec2(sin(u_time * 10.0)/50.0, cos(u_time* 10.0)/50.0);

 position += translate;
 color += vec3(circleshape(position, 0.1))/8.0;
 position += translate;
 color += vec3(circleshape(position, 0.13))/8.0;
 position += translate;
 color += vec3(circleshape(position, 0.16))/8.0;
 position += translate;
 color += vec3(circleshape(position, 0.19))/8.0;
 color += vec3(circleshape(position, 0.21))/8.0;
 color += vec3(circleshape(position, 0.23));
 color -= vec3(circleshape(position, 0.26))*3.0;

 gl_FragColor = vec4(color, 1.0)   ;
}