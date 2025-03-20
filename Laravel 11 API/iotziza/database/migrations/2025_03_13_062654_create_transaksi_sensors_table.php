<?php


use Illuminate\Database\Migrations\Migration;
use Illuminate\Database\Schema\Blueprint;
use Illuminate\Support\Facades\Schema;


return new class extends Migration
{
    /**
     * Run the migrations.
     */
    public function up(): void
    {
        Schema::create('transaksi_sensor', function (Blueprint $table) {
            $table->id('id')->startingValue(1); // Menetapkan AUTO_INCREMENT dimulai dari 1
            $table->string('nama_sensor', 255); // varchar(255)
            $table->integer('nilai1', false)->length(255); // int(255)
            $table->integer('nilai2', false)->length(255); // int(255)
            $table->timestamps(); // Menambahkan created_at dan updated_at
        });
    }
   


    /**
     * Reverse the migrations.
     */
    public function down(): void
    {
        Schema::dropIfExists('transaksi_sensors');
    }
};
