<?php


namespace App\Models;


use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;


class TransaksiSensor extends Model
{
    use HasFactory;
   
    /**
     * The table associated with the model.
     *
     * @var string
     */
    protected $table = 'transaksi_sensor';


    /**
     * The attributes that are mass assignable.
     *
     * @var array
     */
    protected $fillable = [
        'nama_sensor',
        'nilai1',
        'nilai2',
    ];


    /**
     * The attributes that should be hidden for arrays.
     *
     * @var array
     */
    protected $hidden = [];


    /**
     * The attributes that should be cast.
     *
     * @var array
     */
    protected $casts = [];
}
