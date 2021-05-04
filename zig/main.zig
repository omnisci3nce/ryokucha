const std = @import("std");
const expect = @import("std").testing.expect;

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
            .programID = undefined
        };

        return self;
    }
};


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

const log_level_strings = [_][]const u8{"FATAL", "ERROR", "WARN", "INFO", "DEBUG", "TRACE"};

fn log(level: LogLevel, message: []const u8) !void {
    const stdout = std.io.getStdOut().writer();
    try stdout.print("[{s}]: {s}\n", .{log_level_strings[@enumToInt(level)], message});
}

pub fn main() !void {
    // Setup
    const app_conf = ApplicationConfig{
        .start_pos_x = 0,
        .start_pos_y = 0,
        .start_width = 640,
        .start_height = 480,
        .name = "Ryokucha Game Engine"
    };
    
    try log(LogLevel.FATAL, "Application crash.");
}