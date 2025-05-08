<?php


use Illuminate\Support\Facades\Route;
use App\Http\Controllers\GraphController;


Route::get('/', [GraphController::class, 'index'])->name('graph');
Route::get('/graph/export', 	[GraphController::class, 'exportToExcel'])->name('graph.export');  // Pastikan rute ini ada
