'use strict';

var gulp = require('gulp');
var sass = require('gulp-sass');
var cssimport = require('gulp-cssimport');
var inlineSource = require('gulp-inline-source');
var js = require('./bin/build.js');

gulp.task('build:js', js.build); 

gulp.task('watch:js', js.watch);

gulp.task('build:css', function() {
  return gulp.src('./src/css/*.scss')
    .pipe(sass().on('error', sass.logError))
    .pipe(cssimport())
    .pipe(gulp.dest('./static/build'));
});
 
gulp.task('watch:css', function() {
  gulp.watch('./src/css/**/*.scss', ['build:css']);
});

// not currently used
gulp.task('build:html', function() {
  return gulp.src('./static/index.html')
    .pipe(inlineSource())
    .pipe(gulp.dest('./static/build'))
});


gulp.task('build', gulp.series('build:js', 'build:css'));

gulp.task('watch', gulp.series('watch:js', 'watch:css'));
