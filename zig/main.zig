const std = @import("std");

// ---- Maths

const Vec3 = struct {
    x: f32, y: f32, z: f32
};
const Vec2 = struct {
    x: f32, y: f32
};
const Vec4 = struct {
    x: f32, y: f32, z: f32, w: f32
};

const Transform = struct {
    translation: Vec3,
    // scale: Vec3,
    // rotation: Vec3
};

// ---- OpenGL
const ShaderProgram = struct {
    programID: u32,

    pub fn init(vertex_source: []const u8, frag_source: []const u8) ShaderProgram {
        var self = ShaderProgram{
            programID: undefined
        };
    }
}


// ---- Application

const ApplicationConfig = struct {
    start_pos_x: i16,
    start_pos_y: i16,
    start_width: i16,
    start_height: i16,
    name: []const u8
};

// ---- Logging

const LogLevel = enum {
    FATAL,
    ERROR,
    WARN,
    INFO,
    DEBUG,
    TRACE
};

fn FATAL 

pub fn main() void {
    // Setup
    const app_conf = ApplicationConfig{
        .start_pos_x = 0,
        .start_pos_y = 0,
        .start_width = 640,
        .start_height = 480,
        .name = "Ryokucha Game Engine"
    };



    std.debug.print("Hello, {s}!\n", .{"World"});
}