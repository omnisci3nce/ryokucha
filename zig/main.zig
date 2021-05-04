const std = @import("std");

const Vec3 = struct {
    x: f32, y: f32, z: f32
};
const Vec2 = struct {
    x: f32, y: f32
};
const Vec4 = struct {
    x: f32, y: f32, z: f32, w: f32
};

// ---- Application

const ApplicationConfig = struct {
    start_pos_x: i16,
    start_pos_y: i16,
    start_width: i16,
    start_height: i16,
    str
}

const LogLevel = enum {
    FATAL,
    ERROR,
    WARN,
    INFO,
    DEBUG,
    TRACE
};

pub fn main() void {
    std.debug.print("Hello, {s}!\n", .{"World"});
}