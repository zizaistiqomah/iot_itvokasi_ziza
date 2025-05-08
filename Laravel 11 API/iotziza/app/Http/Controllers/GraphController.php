<?php


namespace App\Http\Controllers;


use App\Exports\TransaksiSensorExport;
use Maatwebsite\Excel\Facades\Excel;
use App\Models\TransaksiSensor;


class GraphController extends Controller
{
    /**
     * Menampilkan grafik transaksi sensor.
     *
     * @return \Illuminate\View\View
     */
    public function index()
    {
        // Mengambil data transaksi sensor 
        $transaksiSensors = TransaksiSensor::latest()->take(10)->get();


        // Mengambil data label 
        $labels = $transaksiSensors->pluck('nama_sensor');


        // Mengambil data nilai1 dan nilai2 untuk grafik
        $dataNilai1 = $transaksiSensors->pluck('nilai1');
        $dataNilai2 = $transaksiSensors->pluck('nilai2');


        return view('graph', compact('labels', 'dataNilai1', 'dataNilai2'));
    }


    /**
     * Mengunduh data transaksi sensor dalam format Excel
     *
     * @return \Symfony\Component\HttpFoundation\BinaryFileResponse
     */
    public function exportToExcel()
    {
        return Excel::download(new TransaksiSensorExport, 'transaksi_sensor.xlsx');
    }
}
