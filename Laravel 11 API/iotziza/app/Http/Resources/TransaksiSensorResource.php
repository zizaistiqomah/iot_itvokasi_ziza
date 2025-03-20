<?php


namespace App\Http\Resources;
use Illuminate\Http\Request;
use Illuminate\Http\Resources\Json\JsonResource;


class TransaksiSensorResource extends JsonResource
{
    /**
     * Transform the resource into an array.
     *
     * @param  \Illuminate\Http\Request  $request
     * @return array
     */
    public function toArray($request)
    {
        return [
            'id' => $this->id,
            'nama_sensor' => $this->nama_sensor,
            'nilai1' => $this->nilai1,
            'nilai2' => $this->nilai2,
        ];
    }
}
